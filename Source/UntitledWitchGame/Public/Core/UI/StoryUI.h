// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StoryUI.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API UStoryUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UProgressBar *HealthIndicator;
};
