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
	
	
};
