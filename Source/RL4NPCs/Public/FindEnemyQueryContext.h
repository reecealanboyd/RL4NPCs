// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "MLCharacter.h"
#include "RLController.h"
#include "FindEnemyQueryContext.generated.h"

/**
 * 
 */
UCLASS()
class RL4NPCS_API UFindEnemyQueryContext : public UEnvQueryContext
{
	GENERATED_BODY()
	
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
	
	
};
