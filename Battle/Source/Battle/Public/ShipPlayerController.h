// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Ship.h"
#include "ShipPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_API AShipPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AShip * GetControlledShip() const;
	
	void virtual BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	//move the barral so that the shot would hit where it intersects the world
	void AimAtCrossHair();

private:

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;
	bool GetPlayerLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

};
