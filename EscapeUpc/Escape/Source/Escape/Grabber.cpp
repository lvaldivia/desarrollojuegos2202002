// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"



// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if(InputComponent){
		//UE_LOG(LogTemp,Error,TEXT("Hay"));
		InputComponent->BindAction("Grab",IE_Pressed,this,&UGrabber::Grab);
	}
}

void UGrabber::Grab(){
	UE_LOG(LogTemp,Error,TEXT("GRABBERR GAAAAA"));
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0,255,0),
		false,
		0.f,
		0.f,
		5.0f
	);

	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")),false,GetOwner()); 
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	AActor* ActorHit = Hit.GetActor();
	//UE_LOG(LogTemp,Error,TEXT("Line Trace has hit"));
	if(ActorHit){
			UE_LOG(LogTemp,Error,TEXT("Line Trace has hit %s,"),
					*ActorHit->GetName());
	}else{
	}


}

