// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Weapon.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UWeapon : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNTITLEDWITCHGAME_API IWeapon
{
	GENERATED_BODY()

public:
	virtual void Primary(class UPlayerAnimInstance* instance);
	virtual void Secondary(class UPlayerAnimInstance* instance);
	virtual class UStaticMeshComponent* GetMesh();
	virtual FName Name();
};
