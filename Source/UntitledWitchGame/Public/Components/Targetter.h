// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Targetter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetChanged, AActor*, Target);
/**
 * 
 */
UCLASS()
class UNTITLEDWITCHGAME_API UTargetter : public UBoxComponent
{
	GENERATED_BODY()

	UTargetter();

	UFUNCTION()
	void TargetOverlap(UPrimitiveComponent* OverlappedComponent,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void TargetEndOverlap(class UPrimitiveComponent* OverlappedComp, 
		class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex);





public:
	// class AActor* FindNext();

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FOnTargetChanged OnTargetChanged;

	class AActor* CurrentTarget;
};
