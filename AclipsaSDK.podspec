Pod::Spec.new do |s|
  s.name             = "AclipsaSDK"
  s.version          = "1.0.2"
  s.summary          = "Easily Add Video and Messaging to Your Current and Future Apps."
  s.description      = <<-DESC
                       The Aclipsa Video & Messaging platform allows you to easily add video and text messaging and video content distribution to any iOS or Android app. Your users will be able to upload and watch videos as well as create and send messages to each other quickly and securely.
                       DESC
  s.homepage         = "https://github.com/Aclipsa/messaging-sdk-ios"
  s.license          = 'Not Open Source'
  s.author           = { "Aclipsa" => "info@aclipsa.com" }
  s.source           = { :git => "https://github.com/Aclipsa/messaging-sdk-ios.git", :tag => s.version.to_s }

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.ios.vendored_framework = 'AclipsaSDK/AclipsaSDK.framework'
  s.preserve_path = 'AclipsaSDK/AclipsaSDK.framework'
  s.resource_bundles = {
    'AclipsaSDK' => ['AclipsaSDK/AclipsaSDK.bundle', 'AclipsaSDK/Aclipsa SDK Documentation', 'AclipsaSDKDemo.zip', 'SwiftAclipsaSDKDemo.zip']
  }
end
