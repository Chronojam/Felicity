// Fill out your copyright notice in the Description page of Project Settings.


#include "Placeables/Pickups/WeaponPickup.h"
#include "Core/StoryPlayerState.h"


AWeaponPickup::AWeaponPickup() {

}

void AWeaponPickup::Pickup(AStoryPlayerState* State) {
	State->AddWeapon(Type);
	UE_LOG(LogTemp, Warning, TEXT("Picked up a Weapon!"));
}
