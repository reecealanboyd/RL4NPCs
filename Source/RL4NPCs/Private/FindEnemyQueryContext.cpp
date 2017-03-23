// Fill out your copyright notice in the Description page of Project Settings.

#include "RL4NPCs.h"
#include "FindEnemyQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "RLCharacter.h"
#include "RLController.h"

void UFindEnemyQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	Super::ProvideContext(QueryInstance, ContextData);

	//Get the Owner of this Query and cast it to an actor
	//Then, get the actor's controller and cast to it our AIController
	//This code works for our case but avoid that many casts and one-liners in cpp.
	ARLController* AICon = Cast<ARLController>((Cast<AActor>((QueryInstance.Owner).Get())->GetInstigatorController()));

	if (AICon && AICon->GetSeeingPawn())
	{
		//Set the context SeeingPawn to the provided context data
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, AICon->GetSeeingPawn());
	}
}


