// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCs/FairyTargetter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "AIController.h"

// Sets default values
AFairyTargetter::AFairyTargetter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 3.f;
}

// Called when the game starts or when spawned
void AFairyTargetter::BeginPlay()
{
	Super::BeginPlay();
	
}
void AFairyTargetter::SetTarget(AActor* Tar) {
	if (Target != nullptr) {
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}
	Target = Tar;
	AttachToActor(Target, FAttachmentTransformRules::KeepWorldTransform, NAME_None);
	// TeeHee.
}
// Called every frame
void AFairyTargetter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Target == nullptr) return;

	auto A = GetActorLocation();
	auto B = Target->GetActorLocation() + FVector(0, 0, 50.f);
	FVector direction = UKismetMathLibrary::GetDirectionUnitVector(A, B);

	FVector Final = direction * Speed;

	//UE_LOG(LogTemp, Warning, TEXT("%f: %f: %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z)
	//UE_LOG(LogTemp, Warning, TEXT("%f: %f: %f"), B.X, B.Y, B.Z)
	SetActorLocation(A + Final);

	// Just bob up and down for now..
	//auto fctrl = GetController<AAIController>();
	//auto mTar = Target->GetActorLocation() + FVector(0, 0, 50.f);
	//fctrl->MoveToLocation(mTar);

	// Float around the target
	// auto targetHeight = Target->GetActorLocation() + FVector(0, 0, OrbitHeight);

	/*auto direction = UKismetMathLibrary::GetDirectionUnitVector(
		height,
		GetActorLocation()
	);

	FVector angle = direction.RotateAngleAxis(
		RevolutionsPerSecond * 360 * GetWorld()->GetDeltaSeconds(),
		FVector(0, 0, 1)
	) * FVector(1.0, 1.0, 0) * OrbitRadius;

	SetActorLocation(height + angle);*/
}
