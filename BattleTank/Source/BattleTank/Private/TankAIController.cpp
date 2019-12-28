// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AITankController not possesing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AITankController possessing: %s"), *(ControlledTank->GetName()));
    }

    auto ControlledPlayerTank = GetPlayerTank();
    if (!ControlledPlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIContoller: can't find player tank."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(ControlledPlayerTank->GetName()));
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn)
    {
        return nullptr;
    }
    return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    auto playerTank = GetPlayerTank();
    if (playerTank == nullptr)
    {
        return;
    }
    // TODO Move towards the player

    // Aim towards the player
    GetControlledTank()->AimAt(playerTank->GetActorLocation());

    // Fire if ready

    //UE_LOG(LogTemp, Warning, TEXT("TankAIController: Tick - %f"), DeltaTime);
}