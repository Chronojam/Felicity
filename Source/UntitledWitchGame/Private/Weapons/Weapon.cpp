// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Weapon.h"
#include "Character/PlayerAnimInstance.h"

// Add default functionality here for any IAbility functions that are not pure virtual.
FName IWeapon::Name() {
	return FName(TEXT("None"));
}

void IWeapon::Primary(UPlayerAnimInstance* instance) {
	// Do nothing
}

// Stomp
void IWeapon::Secondary(UPlayerAnimInstance* instance) {

}