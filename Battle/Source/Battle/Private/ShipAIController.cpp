// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipAIController.h"
#include "Engine/World.h"



void AShipAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerShip = GetAIControlledShip();
	if (!PlayerShip) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller cannot found player ship."))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found %s."), *(PlayerShip->GetName()))
	}
}





AShip * AShipAIController::GetPlayerControlledShip() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	else { return Cast<AShip>(PlayerPawn); }
}



AShip* AShipAIController::GetAIControlledShip() const 
{
	return Cast<AShip>(GetPawn());
}