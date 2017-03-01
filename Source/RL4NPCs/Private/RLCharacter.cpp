// Fill out your copyright notice in the Description page of Project Settings.

#include "RL4NPCs.h"
#include "RLCharacter.h"


// Sets default values
ARLCharacter::ARLCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Implement CalculateDead
void ARLCharacter::CalculateDead()
{
	if (health <= 0) {
		isDead = true;
	}
	else {
		isDead = false;
	}
}

// Implement CalculateHealth
void ARLCharacter::CalculateHealth(float delta)
{
	health += delta;
	CalculateDead();
}

// Implement PostEditChangeProperty
#if WITH_EDITOR
void ARLCharacter::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
	isDead = false;
	health = 100;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}
#endif

// Called when the game starts or when spawned
void ARLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

