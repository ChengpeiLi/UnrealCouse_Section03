// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShipAimingComponent.generated.h"

class UShipBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_API UShipAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShipAimingComponent();

protected:
	// Called when the game starts


public:	
	// Called every frame
	//TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UShipBarrel* BarrelToSet);
private:
	UShipBarrel * Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
	float DegreesPerSecond = 5.0;
};
