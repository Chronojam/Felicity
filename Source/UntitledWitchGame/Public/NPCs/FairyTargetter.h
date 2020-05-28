// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FairyTargetter.generated.h"

UCLASS()
class UNTITLEDWITCHGAME_API AFairyTargetter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFairyTargetter();

	UPROPERTY(EditAnywhere)
	float Speed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetTarget(AActor* Target);

	AActor* Target;
};
