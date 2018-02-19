// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"


// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipAimingComponent = CreateDefaultSubobject<UShipAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShip::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	ShipAimingComponent->SetBarrelReference(BarrelToSet);
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AShip::AimAt(FVector HitLocation)
{
	ShipAimingComponent->AimAt(HitLocation);

}