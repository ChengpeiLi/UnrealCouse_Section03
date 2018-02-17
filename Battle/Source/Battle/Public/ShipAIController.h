// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Ship.h"
#include "ShipAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_API AShipAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AShip * GetAIControlledShip() const;

	void virtual BeginPlay() override;
	
	void virtual Tick(float DeltaTime) override;
	
	AShip* GetPlayerControlledShip() const;

	
};
