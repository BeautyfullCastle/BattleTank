// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel;

// Makes the barrel aiming at the target.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
    GENERATED_BODY()

public:	
    // Sets default values for this component's properties
    UTankAimingComponent();

public:
    void AimAt(FVector TargetLocation, float LaunchSpeed) const;

    void SetBarrelReference(UTankBarrel* BarrelToSet);

private:
    void MoveBarrelTowards(FVector AimDirection) const;

private:
    UTankBarrel* Barrel = nullptr;
};
