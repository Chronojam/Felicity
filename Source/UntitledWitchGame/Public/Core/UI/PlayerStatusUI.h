// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatusUI.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API UPlayerStatusUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar *HealthIndicator;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage *Moon_Rune;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage *Sun_Rune;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage *Broom_Weapon;


	UFUNCTION()
	void OnStateChanged(class AStoryPlayerState *State);
};
