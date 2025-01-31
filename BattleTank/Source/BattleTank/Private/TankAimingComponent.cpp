// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true; // TODO Should this really tick?

    // ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) const
{
    if (Barrel == nullptr)
    {
        return;
    }

    FVector OutLaunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

    // Calcalate OutLaunchVelocity
    if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity,
        StartLocation, HitLocation, LaunchSpeed))
    {
        auto TankName = GetOwner()->GetName();
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(AimDirection);
        
        auto Time = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution found"), Time);
    }
    else 
    {
        auto Time = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
    }
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
    Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const
{
    // Work-out difference between current barrel rotation, and AimDirection
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;

    Barrel->Elevate(5); // TODO remove magic number
}