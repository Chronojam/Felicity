// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "ObjectiveListEntry.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API UObjectiveListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock *ObjectiveText;
};
