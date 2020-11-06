// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "ToonTanks/TankModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	UE_LOG(LogTemp,Error,TEXT("Inicio :'v"));
	Super::BeginPlay();
	Health = DefaultHealth;
	GameModeRef = Cast<ATankModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::TakeDamage);	
	
}

void UHealthComponent::TakeDamage(AActor* DamageActor, float Damage,const UDamageType* DamageType,
			AController* InstigatedBody, AActor* DamageCauser){
	
	if(Damage== 0 || Health <= 0){
		return;
	}
	Health = FMath::Clamp(Health - Damage,0.0f,DefaultHealth);
	UE_LOG(LogTemp,Error,TEXT("DAÑO :'v"));
	if(Health <= 0){
		if(GameModeRef){
			UE_LOG(LogTemp,Error,TEXT("MORI :'v"));
			GameModeRef->ActorDied(GetOwner());
		}else{
			UE_LOG(LogTemp,Error,TEXT("NO hay gameModeRef :'v"));
		}
	}
}

