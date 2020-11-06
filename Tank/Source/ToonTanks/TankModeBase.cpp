// Fill out your copyright notice in the Description page of Project Settings.


#include "TankModeBase.h"
#include "ToonTanks\PawnTank.h"
#include "ToonTanks\PawnTurret.h"
#include "Kismet\GameplayStatics.h"

void ATankModeBase::BeginPlay(){
    Super::BeginPlay();
    HandleGameStart();
}

void ATankModeBase::ActorDied(AActor* DeadActor){
    UE_LOG(LogTemp,Error,TEXT("ACTOR DEAD"));
    if(DeadActor == PlayerTank){
        PlayerTank->HandleDestruction();
        HandleGameOver(false);
    }else if(APawnTurret* DestroyedTurrent= Cast<APawnTurret>(DeadActor)){
        DestroyedTurrent->HandleDestruction();
        TargetTurrents--;
        if(TargetTurrents <= 0){
            HandleGameOver(true);
        }
    }
}

void ATankModeBase::HandleGameStart(){
    TargetTurrents = GetTargetTurrentCount();
    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));
    GameStart();
}
void ATankModeBase::HandleGameOver(bool PlayerWon){
    GameOver(PlayerWon);
}

int32 ATankModeBase::GetTargetTurrentCount(){
    TArray<AActor*>TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),APawnTurret::StaticClass(),TurretActors);
    return TurretActors.Num();

}