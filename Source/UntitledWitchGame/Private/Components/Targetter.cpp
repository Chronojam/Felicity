// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Targetter.h"
#include "World/Targetable.h"

UTargetter::UTargetter() 
{
	OnComponentBeginOverlap.AddDynamic(this, &UTargetter::TargetOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UTargetter::TargetEndOverlap);
}

void UTargetter::TargetOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) {
	if (OtherActor->Implements<UTargetable>()) {
		UE_LOG(LogTemp, Warning, TEXT("Targetted: %s"), *OtherActor->GetName());
		if (CurrentTarget == nullptr) {
			CurrentTarget = OtherActor;
			OnTargetChanged.Broadcast(OtherActor);
		}
	}
}

void UTargetter::TargetEndOverlap(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex) {
	if (OtherActor->Implements<UTargetable>()) {
		if (CurrentTarget == OtherActor) {
			CurrentTarget = nullptr;
			OnTargetChanged.Broadcast(OtherActor);
		}
	}
}
