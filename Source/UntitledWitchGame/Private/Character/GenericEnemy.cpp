// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GenericEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AGenericEnemy::AGenericEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetCanBeDamaged(true);
	GetCharacterMovement()->MaxWalkSpeed = 200.f;
	Health = 100;
}

// Called when the game starts or when spawned
void AGenericEnemy::BeginPlay()
{
	Super::BeginPlay();
	//this->OnTakeAnyDamage.AddDynamic(this, &AGenericEnemy::ReceiveAnyDamage);
}

// Called every frame
void AGenericEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called when this actor takes any damage.
float AGenericEnemy::TakeDamage(float Damage,
	const FDamageEvent& DamageEvent,
	AController* InstigatedBy,
	AActor* DamageCauser) {

	Super::TakeDamage(Damage, DamageEvent, InstigatedBy, DamageCauser);

	// Just make the baddie vanish for now.
	Health -= Damage;
	if (Health <= 0) {
		Destroy();
	}

	return Damage;
}