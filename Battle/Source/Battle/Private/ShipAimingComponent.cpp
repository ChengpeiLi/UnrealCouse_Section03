// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipAimingComponent.h"
#include "ShipBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UShipAimingComponent::UShipAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts


void UShipAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.0,
		0.0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		auto AimDiection = OutLaunchVelocity.GetSafeNormal();
		auto ShipName = GetOwner()->GetName();
		MoveBarrelTowards(AimDiection);
			

	}
	else { return; }
}

void UShipAimingComponent::SetBarrelReference(UShipBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UShipAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//given max move speed and frame time
	//get the barrel rotation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	

	Barrel->Elevate(DegreesPerSecond);
	//equate the pitch of the barrel to the pitch of aim direction
	//get turret rotation
	//equate the yaw of the turret to the yaw of aim direction
}

