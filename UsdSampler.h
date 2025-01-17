// Copyright 2020 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "UsdBridgedBaseObject.h"

struct UsdSamplerData
{
  UsdSharedString* name = nullptr;
  UsdSharedString* usdName = nullptr;

  double timeStep = 0.0;
  int timeVarying = 0; // Bitmask indicating which attributes are time-varying. 0:fileName, 1:wrapS, 2:wrapT

  UsdSharedString* fileName = nullptr;
  UsdSharedString* wrapS = nullptr;
  UsdSharedString* wrapT = nullptr;
  UsdSharedString* wrapR = nullptr;
};

class UsdSampler : public UsdBridgedBaseObject<UsdSampler, UsdSamplerData, UsdSamplerHandle>
{
  protected:
    enum SamplerType
    {
      SAMPLER_UNKNOWN = 0,
      SAMPLER_1D,
      SAMPLER_2D,
      SAMPLER_3D
    };

  public:
    UsdSampler(const char* name, const char* type, UsdBridge* bridge, UsdDevice* device);
    ~UsdSampler();

    void filterSetParam(const char *name,
      ANARIDataType type,
      const void *mem,
      UsdDevice* device) override;

    void filterResetParam(
      const char *name) override;

  protected:
    bool deferCommit(UsdDevice* device) override;
    bool doCommitData(UsdDevice* device) override;
    void doCommitRefs(UsdDevice* device) override {}

    SamplerType samplerType = SAMPLER_UNKNOWN;

};