// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipPlayerController.h"

AShip* AShipPlayerController::GetControlledShip() const {

	return Cast<AShip>(GetPawn());
}


