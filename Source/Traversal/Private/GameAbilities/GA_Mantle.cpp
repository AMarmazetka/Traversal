// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilities/GA_Mantle.h"

void UGA_Mantle::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) {
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	UE_LOG(LogTemp, Warning, TEXT("[UGA_Mantle] Test Activation"));

	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}