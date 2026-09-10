// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TraversalObjects.h"
#include "TraversalObject.generated.h"

UCLASS()
class TRAVERSAL_API ATraversalObject : public AActor, public ITraversalObjects
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATraversalObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool CanTraverse_Implementation() const override;
};
