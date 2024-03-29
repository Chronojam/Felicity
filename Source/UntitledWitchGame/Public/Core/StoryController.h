// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StoryController.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API AStoryController : public APlayerController
{
	GENERATED_BODY()

public:
	AStoryController();
	void BeginPlay() override;
	void Tick(float dt) override;

	UPROPERTY(EditAnywhere, Category = UI)
	TSubclassOf<class UUserWidget> ObjectivesUIClass;

	UPROPERTY(EditAnywhere, Category = UI)
	TSubclassOf<class UUserWidget> PlayerStatusUIClass;

	class UPlayerStatusUI* PlayerStatusUI;
	class UObjectivesUI* ObjectivesUI;
};
