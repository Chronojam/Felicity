// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "StoryPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerStateUpdated, AStoryPlayerState*, State);

UCLASS()
class UNTITLEDWITCHGAME_API AStoryPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> StateUIClass;

	UPROPERTY(BlueprintAssignable)
	FPlayerStateUpdated OnStateChanged;

	float MaxHealth;
	float Health;

	TArray<enum Item> Items;

protected:
	virtual void BeginPlay() override;

public:
	void AlterHealth(float a);
	void AddItem(Item item);
};