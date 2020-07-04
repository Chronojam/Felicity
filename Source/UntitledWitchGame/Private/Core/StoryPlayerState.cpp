// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/StoryPlayerState.h"
#include "Placeables/Pickups/Items.h"
#include "Weapons/WeaponBroom.h"
#include "Weapons/Weapon.h"
#include "Core/ObjectiveInfo.h"


void AStoryPlayerState::BeginPlay() {
	Super::BeginPlay();

	Health = 25.0f;
	MaxHealth = 200.0f;

	OnStateChanged.Broadcast(this);

	// Just instantiate these for now
	// so we can uniquely add them later as we pick them up.
	BroomAbility = Cast<IWeapon>(NewObject<UWeaponBroom>());

	// For now just say we've got it.
	CurrentAbility = BroomAbility;
}

void AStoryPlayerState::AlterHealth(float a) {
	Health += a;
	if (Health > MaxHealth) {
		Health = MaxHealth;
	}

	// Tell all the listeners that the health has been updated.
	OnStateChanged.Broadcast(this);
}
void AStoryPlayerState::AddItem(Item item) {
	this->Items.AddUnique(item);

	// If we pick up an ability-like item then 
	// also allow us to use the ability immediately.
	switch (item) {
	case Item::Ability_Broom:
		this->Abilites.AddUnique(BroomAbility);
		break;
	case Item::Ability_IceWand:
		break;
	case Item::Ability_FireWand:
		break;
	case Item::Ability_EarthWand:
		break;
	case Item::Ability_AirWand:
		break;
	default:
		break;
	}

	// Tell all listeners that we've picked something up.
	OnStateChanged.Broadcast(this);
}