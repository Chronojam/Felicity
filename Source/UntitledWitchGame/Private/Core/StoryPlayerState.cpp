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
	CurrentWeapon = WeaponItem::None;

	OnStateChanged.Broadcast(this);
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
	OnStateChanged.Broadcast(this);
}

void AStoryPlayerState::AddWeapon(WeaponItem weapon) {
	if (!this->Weapons.Contains(weapon)) {
		// Tell all listeners that we've picked a new weapon up.
		OnWeaponAdded.Broadcast(weapon);
	}
	this->Weapons.AddUnique(weapon);
	if (CurrentWeapon == WeaponItem::None) {
		UE_LOG(LogTemp, Warning, TEXT("Equipping"));
		EquipWeapon(weapon);
	}
}

void AStoryPlayerState::EquipWeapon(WeaponItem weapon) {
	// Check if we've actually got the weapon we're reqesting
	// to equip
	if (!this->Weapons.Contains(weapon)) return;

	UE_LOG(LogTemp, Warning, TEXT("Setting Current"));
	CurrentWeapon = weapon;
	OnWeaponEquipped.Broadcast(weapon);
}