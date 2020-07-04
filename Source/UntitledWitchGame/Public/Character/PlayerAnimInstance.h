// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Animation")
	bool IsPlayingAnyMontage;

	// Plays the swing animation
	UFUNCTION(BlueprintImplementableEvent, Category = "Animation")
	void PlaySwing();
};
