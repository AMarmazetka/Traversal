#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TraversalObjects.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UTraversalObjects : public UInterface
{
	GENERATED_BODY()
};

class TRAVERSAL_API ITraversalObjects
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanTraverse() const;
};