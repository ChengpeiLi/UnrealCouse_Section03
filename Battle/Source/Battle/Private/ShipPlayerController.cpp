// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipPlayerController.h"

void AShipPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledShip = GetControlledShip();
	if (!ControlledShip) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a ship."))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing %s."), *(ControlledShip->GetName()))
	}
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play."))
}

AShip* AShipPlayerController::GetControlledShip() const {
	
	return Cast<AShip>(GetPawn());
}


