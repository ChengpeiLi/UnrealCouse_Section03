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
};
