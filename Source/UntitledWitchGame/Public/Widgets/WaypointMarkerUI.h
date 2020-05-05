// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaypointMarkerUI.generated.h"


/**
 * 
 */
UCLASS(Abstract)
class UNTITLEDWITCHGAME_API UWaypointMarkerUI : public UUserWidget
{
	GENERATED_BODY()

protected:

	/* Actor that widget is attached to via WidgetComponent */
	UPROPERTY(VisibleAnywhere)
		AActor* OwningActor;

public:

	/* Set the owning actor so widgets have access to whatever is, broadcasting OnOwningActorChanged event */
	UFUNCTION(BlueprintCallable)
		void SetOwningActor(AActor* NewOwner);
	
};
