// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	// Start the tank moving the barrel so that a shot would it where
	// the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;
    UPROPERTY(EditAnywhere)
        float LineTraceRange = 1000000.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};