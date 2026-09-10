// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAbilities/GA_Vault.h"

void UGA_Vault::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) {
	UE_LOG(LogTemp, Warning, TEXT("[UGA_Vault] PreSuper Test Activation"));
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	UE_LOG(LogTemp, Warning, TEXT("[UGA_Vault] Test Activation"));


	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}