/* -*- mode: c; tab-width: 4; indent-tabs-mode: nil; -*- */

#pragma once

// Logging stuff ...
DECLARE_LOG_CATEGORY_EXTERN(LogUE4Orc, Log, All);

#include "mongoose.h"
#include "types.h"

class UE4ORCHESTRATOR_API URCHTTP : public FTickableGameObject
{
  public:
    URCHTTP();
    ~URCHTTP();

    void Init();

    static URCHTTP& Get();

    /*
     *  FTickableObject interface.
     */
    virtual void    Tick(float dt)                  override;
    virtual TStatId GetStatId()             const   override;
    virtual bool    IsTickable()            const { return true; }
    virtual bool    IsTickableWhenPaused()  const { return true; }
    virtual bool    IsTickableInEditor()    const { return true; }

    void SetPollInterval(int v);

  private:
    struct mg_mgr         mgr;
    struct mg_connection* conn;

    /*
     *  The poll_interval dictates how often we wish to poll.  If
     *  this is set to 0 (default), it will invoke a poll of
     *  `poll_ms` (default=1ms) each time this plugin gets a tick.
     *  However, if this is set to N (N > 0), this will only call
     *  poll once every N ticks.
     */
    int poll_interval;
    int poll_ms;

    /* Pak file */

public:
    static int mountPakFile(const FString &);
};
