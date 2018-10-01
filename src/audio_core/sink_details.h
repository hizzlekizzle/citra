// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace AudioCore {

class Sink;

/// Retrieves the IDs for all available audio sinks.
std::vector<const char*> GetSinkIDs();

/// Gets the list of devices for a particular sink identified by the given ID.
std::vector<std::string> GetDeviceListForSink(std::string_view sink_id);

/// Creates an audio sink identified by the given device ID.
std::unique_ptr<Sink> CreateSinkFromID(std::string_view sink_id, std::string_view device_id);
    SinkDetails(const char* id_, FactoryFn factory_, ListDevicesFn list_devices_, bool is_sync_)
        : id(id_), factory(std::move(factory_)), list_devices(std::move(list_devices_)), is_sync(is_sync_) {}

    /// Name for this sink.
    const char* id;
    /// A method to call to construct an instance of this type of sink.
    FactoryFn factory;
    /// A method to call to list available devices.
    ListDevicesFn list_devices;
    /// If this sink should be handled synchronously.
    bool is_sync;
};

extern const std::vector<SinkDetails> g_sink_details;

const SinkDetails& GetSinkDetails(std::string_view sink_id);

} // namespace AudioCore
