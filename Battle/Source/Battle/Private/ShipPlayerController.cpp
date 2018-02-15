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


void AShipPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrossHair();
}

void AShipPlayerController::AimAtCrossHair()
{
	if (!GetControlledShip()) { return; }
	FVector HitLocation; //Out Parameter
	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString())
	}
}

bool AShipPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	//deproject the screen position of crosshair position of the crosshair to world position
	FVector LookDirection;
	if (GetPlayerLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString())
	}

	//linetrace along that look direction, and see what we hit
	
	return true;
}

bool AShipPlayerController::GetPlayerLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector WorldLocation;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
	//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString())

	return true;
}




AShip* AShipPlayerController::GetControlledShip() const {
	
	return Cast<AShip>(GetPawn());
}


