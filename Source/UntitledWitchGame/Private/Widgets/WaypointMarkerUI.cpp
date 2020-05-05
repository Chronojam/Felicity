// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/WaypointMarkerUI.h"


void UWaypointMarkerUI::SetOwningActor(AActor* NewOwner)
{
	if (OwningActor == NewOwner)
	{
		// Skip repeated calls
		return;
	}

	OwningActor = NewOwner;
}