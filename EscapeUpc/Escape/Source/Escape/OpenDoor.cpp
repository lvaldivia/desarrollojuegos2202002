// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;
	ActorOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!ActorOpen){
		UE_LOG(LogTemp,Error,TEXT("NO HAY PLAYER"));
	}
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp,Error,TEXT("%s"),*GetOwner()->GetActorRotation().ToString());
	//UE_LOG(LogTemp,Error,TEXT("Yaw is %f*"),GetOwner()->GetActorRotation().Yaw);

	//float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	//FRotator OpenDoor(0.0f,TargetYaw,0.f);
	//OpenDoor.Yaw = FMath::Lerp(CurrentYaw,TargetYaw,0.02f);
	//OpenDoor.Yaw = FMath::FInterpConstantTo(CurrentYaw,TargetYaw,DeltaTime,45);
	//GetOwner()->SetActorRotation(OpenDoor);
	if(Pressure && Pressure->IsOverlappingActor(ActorOpen)){
		OpenDoor(DeltaTime);
		UE_LOG(LogTemp,Error,TEXT("GAA"));
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}else{
		if(GetWorld()->GetTimeSeconds() - DoorLastOpened > DoorCloseDelay){
			CloseDoor(DeltaTime);
		}
		
	}
}

void UOpenDoor::OpenDoor(float DeltaTime){
	CurrentYaw = FMath::Lerp(CurrentYaw,TargetYaw,DeltaTime);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}


void UOpenDoor::CloseDoor(float DeltaTime){
	CurrentYaw = FMath::Lerp(CurrentYaw,InitialYaw,DeltaTime);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}

