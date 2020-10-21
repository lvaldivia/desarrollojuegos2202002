// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"


void ATurret::BeginPlay(){
    Super::BeginPlay();
    SetTimer();
    Player = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}

void ATurret::SetTimer(){
    GetWorld()->GetTimerManager().SetTimer(FireRateTimeHandle,this,
                    &ATurret::CheckFireCondition,
                    FireRate,true);
}

void ATurret::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    if(!Player || ReturnDistanceToPlayer() >  FireRange){
        return;
    }
    RotateTurret(Player->GetActorLocation());
}


 void ATurret::HandleDestruction() {
     Super::HandleDestruction();
     Destroy();
 }


void ATurret::CheckFireCondition(){
    if(!Player){
        return;
    }
    if(ReturnDistanceToPlayer()<= FireRange){
        UE_LOG(LogTemp,Error,TEXT("FIre condition :'v"));
    }
}

float ATurret::ReturnDistanceToPlayer(){
    if(!Player){
        return 0.0f;
    }
    return FVector::Dist(Player->GetActorLocation(), GetActorLocation());
}

