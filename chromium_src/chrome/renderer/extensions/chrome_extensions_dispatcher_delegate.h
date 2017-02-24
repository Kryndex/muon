// Copyright 2016 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_RENDERER_EXTENSIONS_CHROME_EXTENSIONS_DISPATCHER_DELEGATE_H_
#define CHROME_RENDERER_EXTENSIONS_CHROME_EXTENSIONS_DISPATCHER_DELEGATE_H_

#include <set>
#include <string>
#include "base/macros.h"
#include "extensions/renderer/dispatcher_delegate.h"

namespace content {
class RenderViewObserver;
}

class ChromeExtensionsDispatcherDelegate
    : public extensions::DispatcherDelegate {
 public:
  ChromeExtensionsDispatcherDelegate();
  ~ChromeExtensionsDispatcherDelegate() override;

 private:
  // extensions::DispatcherDelegate implementation.
  void InitOriginPermissions(const extensions::Extension* extension,
                             bool is_extension_active) override;
  void RegisterNativeHandlers(extensions::Dispatcher* dispatcher,
                              extensions::ModuleSystem* module_system,
                              extensions::ScriptContext* context) override;
  void PopulateSourceMap(
      extensions::ResourceBundleSourceMap* source_map) override;
  void RequireAdditionalModules(extensions::ScriptContext* context) override;
  void OnActiveExtensionsUpdated(
      const std::set<std::string>& extensions_ids) override;

  DISALLOW_COPY_AND_ASSIGN(ChromeExtensionsDispatcherDelegate);
};

#endif  // CHROME_RENDERER_EXTENSIONS_CHROME_EXTENSIONS_DISPATCHER_DELEGATE_H_
