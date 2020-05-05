// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ObjectivesUI.h"
#include "Widgets/ObjectiveListEntry.h"
#include "Components/TextBlock.h"
#include "Components/ListView.h"
#include "World/Objective.h"

/*
void UObjectivesUI::OnObjectiveChanged(AObjective* obj) {
	if (ObjectivesListEntryClass == nullptr) return;

	// Update the objectives list, for now lets just add whatever we recieve.
	auto TestEntry = CreateWidget<UObjectiveListEntry>(this, ObjectivesListEntryClass);
	TestEntry->ObjectiveText->SetText(FText::FromString(info->Description));
	ObjectivesList->AddItem(TestEntry);
}
*/

void UObjectivesUI::OnObjectiveCompleted(class AObjective* completed) {
	UE_LOG(LogTemp, Warning, TEXT("Objective Completed..."));
	// Remove the completed objective from the list.
	// Maybe this will work, it doesnt work.
	// RIP.
	
	// This is historically bad programming....
	for (int i = 0; i < ObjectivesList->GetListItems().Num(); i++) {
		UObjectiveListEntry* entry = Cast<UObjectiveListEntry>(ObjectivesList->GetItemAt(i));
		if (entry->ObjectiveText->Text.EqualToCaseIgnored(FText::FromString(completed->Description))) {
			ObjectivesList->RemoveItem(entry);
			break;
		}
	}
	//ObjectivesList->RemoveItem(completed);

	// If next is active and its actually been set, then
	// add that to the objectives list.
	if (completed->Next != nullptr && completed->Next->Active) {
		UE_LOG(LogTemp, Warning, TEXT("Adding followup Objective..."))
		AddObjective(completed->Next);
	}

	// This definately shouldnt belong here, but lets destroy the completed
	// objective so it cant trigger multiple times.
	completed->Destroy();
}

void UObjectivesUI::AddObjective(AObjective* obj) {
	auto NewObjWidget = CreateWidget<UObjectiveListEntry>(this, ObjectivesListEntryClass);
	NewObjWidget->ObjectiveText->SetText(FText::FromString(obj->Description));
	ObjectivesList->AddItem(NewObjWidget);
}