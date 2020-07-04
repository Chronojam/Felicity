// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponBroom.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Character/PlayerAnimInstance.h"


AWeaponBroom::AWeaponBroom() {
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(Mesh);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AWeaponBroom::BeginOverlap);
}

// Swing
void AWeaponBroom::Primary(UPlayerAnimInstance* instance) {
	instance->PlaySwing();
}

// Stomp
void AWeaponBroom::Secondary(UPlayerAnimInstance* instance) {
	
}

// Name
FName AWeaponBroom::Name() {
	return FName(TEXT("Broom"));
}

UStaticMeshComponent* AWeaponBroom::GetMesh() {
	return Mesh;
}

void AWeaponBroom::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{

}