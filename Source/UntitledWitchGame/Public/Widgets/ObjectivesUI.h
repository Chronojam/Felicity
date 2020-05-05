// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectivesUI.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API UObjectivesUI : public UUserWidget
{
	GENERATED_BODY()



public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UListView *ObjectivesList;

	UFUNCTION()
	void AddObjective(class AObjective* obj);

	UFUNCTION()
	void OnObjectiveCompleted(class AObjective* completed);

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> ObjectivesListEntryClass;
};
