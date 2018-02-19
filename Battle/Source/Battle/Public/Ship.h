// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShipAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

UCLASS()
class BATTLE_API AShip : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UShipAimingComponent* ShipAimingComponent = nullptr;
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Sets default values for this pawn's properties
	AShip();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
