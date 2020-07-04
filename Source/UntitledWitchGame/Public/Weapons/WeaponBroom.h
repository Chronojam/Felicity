// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "GameFramework/Actor.h"
#include "WeaponBroom.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API AWeaponBroom : public AActor, public IWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Collider;

	AWeaponBroom();

public:
	virtual void Primary(class UPlayerAnimInstance* instance) override;
	virtual void Secondary(class UPlayerAnimInstance* instance) override;
	virtual class UStaticMeshComponent* GetMesh() override;
	virtual FName Name() override;


	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
};
