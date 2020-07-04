// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "StoryPlayerState.generated.h"


enum Item;
enum WeaponItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerStateUpdated, AStoryPlayerState*, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerPickedUpWeapon, WeaponItem, weapon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerEquipWeapon, WeaponItem, weapon);

UCLASS()
class UNTITLEDWITCHGAME_API AStoryPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> StateUIClass;

	UPROPERTY(BlueprintAssignable)
	FPlayerStateUpdated OnStateChanged;

	UPROPERTY(BlueprintAssignable)
	FPlayerPickedUpWeapon OnWeaponAdded;

	UPROPERTY(BlueprintAssignable)
	FPlayerEquipWeapon OnWeaponEquipped;

	float MaxHealth;
	float Health;

	// List of items we've acquired.
	TArray<Item> Items;

	// List of abilities avaliable to us
	TArray<WeaponItem> Weapons;

	// What we're currently using.
	WeaponItem CurrentWeapon;
protected:
	virtual void BeginPlay() override;

public:
	void AlterHealth(float a);
	void AddItem(Item item);
	void AddWeapon(WeaponItem weapon);
	void EquipWeapon(WeaponItem weapon);
};
