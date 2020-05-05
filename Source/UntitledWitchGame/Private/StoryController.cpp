// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryController.h"
#include "StoryPlayerState.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/ObjectiveListEntry.h"
#include "Widgets/ObjectivesUI.h"
#include "Widgets/WaypointMarkerUI.h"
#include "Widgets/PlayerStatusUI.h"
#include "World/Objective.h"
#include "Components/TextBlock.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"

AStoryController::AStoryController() {}

void AStoryController::BeginPlay() {
	// Setup all the UI elements
	if (ObjectivesUIClass == nullptr) return;
	if (PlayerStatusUIClass == nullptr) return;

	ObjectivesUI = CreateWidget<UObjectivesUI>(this, ObjectivesUIClass);
	if (ObjectivesUI == nullptr) return;
	PlayerStatusUI = CreateWidget<UPlayerStatusUI>(this, PlayerStatusUIClass);
	if (PlayerStatusUI == nullptr) return;

	ObjectivesUI->AddToViewport();
	PlayerStatusUI->AddToViewport();
	
	// Setup delegate bindings
	auto State = GetPlayerState<AStoryPlayerState>();
	if (State == nullptr) return;

	State->OnStateChanged.AddDynamic(PlayerStatusUI, &UPlayerStatusUI::OnStateChanged);

	// Try and find all the objectives in the world.
	TArray<AActor* > OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AObjective::StaticClass(), OutActors);

	// Get all the initial objectives.
	for (auto i = 0; i < OutActors.Num(); i++) {
		auto obj = Cast<AObjective>(OutActors[i]);
		UE_LOG(LogTemp, Warning, TEXT("Registering Objective: %s"), *obj->GetName())
		// Only add them if they are active.
		// thats how we'll determine if they are an initial objective.
		if (obj->Active) {
			ObjectivesUI->AddObjective(obj);
		}

		// subscribe the UI to everything anyway.
		// probably will cause buggy behaviour like skipping
		// objectives
		obj->OnObjectiveCompleted.AddDynamic(ObjectivesUI, &UObjectivesUI::OnObjectiveCompleted);
	}
}